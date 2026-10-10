// The genetics a seed, plant or cannabis item carries.
//
// A named strain (Strain != "") is fully described by its entry in the strain registry (profiles/CannabisPlus/
// Strains/<Strain>.json): its traits, stability and parents come from there, so all items of one named strain
// are alike and stack. An unknown cross (Strain == "", from breeding) keeps its own numbers in the record.
enum CP_ETrait
{
	POTENCY,
	YIELD,
	SPEED,
	HARDINESS,
	RESIN,
	CBD,
	AROMA,
	COUNT
}

class CP_StrainRecord
{
	string Strain;					// registry name, "" = unknown cross
	ref array<int> Traits;			// unknown cross only: CP_ETrait.COUNT values, 0..100
	int Stability;					// unknown cross only
	int Generation;					// unknown cross only
	string ParentA;					// unknown cross only: the two strains (or line keys) it came from
	string ParentB;

	void CP_StrainRecord(string strain = "")
	{
		Strain = strain;
		Traits = new array<int>;
	}

	static CP_StrainRecord Named(string strain)
	{
		return new CP_StrainRecord(strain);
	}

	bool IsNamed()
	{
		return Strain != "";
	}

	CP_StrainRecord Copy()
	{
		CP_StrainRecord copy = new CP_StrainRecord(Strain);
		copy.Traits.Copy(Traits);
		copy.Stability = Stability;
		copy.Generation = Generation;
		copy.ParentA = ParentA;
		copy.ParentB = ParentB;
		return copy;
	}

	// Identifies the record: equal keys = same genetics (items with equal keys may stack).
	string GetKey()
	{
		if (IsNamed())
			return "S:" + Strain;

		string traits = "";
		foreach (int value : Traits)
		{
			traits += value.ToString() + ",";
		}
		return "U:" + traits + ";" + Stability + ";" + Generation + ";" + ParentA + ";" + ParentB;
	}

	// Rebuilds a record from GetKey(). Returns null for anything else.
	static CP_StrainRecord FromKey(string key)
	{
		if (key.IndexOf("S:") == 0)
			return Named(key.Substring(2, key.Length() - 2));

		if (key.IndexOf("U:") != 0)
			return null;

		TStringArray parts = new TStringArray;
		key.Substring(2, key.Length() - 2).Split(";", parts);
		if (parts.Count() < 5)
			return null;

		CP_StrainRecord record = new CP_StrainRecord();
		TStringArray values = new TStringArray;
		parts[0].Split(",", values);
		foreach (string value : values)
		{
			if (value != "")
				record.Traits.Insert(value.ToInt());
		}
		record.Stability = parts[1].ToInt();
		record.Generation = parts[2].ToInt();
		record.ParentA = parts[3];
		record.ParentB = parts[4];
		return record;
	}

	bool Equals(CP_StrainRecord other)
	{
		return other && other.GetKey() == GetKey();
	}

	// ------------------------------------------------------------------ storage (inside CF mod storage)

	void Write(CF_ModStorage ctx)
	{
		ctx.Write(Strain);
		ctx.Write(Stability);
		ctx.Write(Generation);
		ctx.Write(ParentA);
		ctx.Write(ParentB);
		ctx.Write(Traits.Count());
		foreach (int value : Traits)
		{
			ctx.Write(value);
		}
	}

	bool Read(CF_ModStorage ctx)
	{
		int count;
		if (!ctx.Read(Strain) || !ctx.Read(Stability) || !ctx.Read(Generation) || !ctx.Read(ParentA) || !ctx.Read(ParentB) || !ctx.Read(count))
			return false;

		Traits.Clear();
		for (int i = 0; i < count; i++)
		{
			int value;
			if (!ctx.Read(value))
				return false;
			Traits.Insert(value);
		}
		return true;
	}
}
