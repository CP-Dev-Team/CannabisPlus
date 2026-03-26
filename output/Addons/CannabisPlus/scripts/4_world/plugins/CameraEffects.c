// File dealing with camera effects and functions to aid in their usage.
class CameraEffects extends PPEffects
{
	
	// Constant assignments and initialization. 
	static float EXPOSURE = 0.0;
	static float CHROMABERX = 0.0;
	static float CHROMABERY = 0.0;
	static float HUESHIFT = 0.0;

	static float ROTBLUR = 0.0;
	static float MINDEPTH = 2.5;
	static float MAXDEPTH = 4.5;

	static float RADBLURX = 0.0;
	static float RADBLURY = 0.0;
	static float RADBLUROFFX = 0.0;
	static float RADBLUROFFY = 0.0;

	static float SHARPNESS = 0.0;
	static float GRAIN_SIZE = 0.0;

	static float VIGNETTE = 0.0;
	static float VARGB[4] = { 0, 0, 0, 0 };

	static float CARGB[4] = { 0, 0, 0, 1 }; 

	static float CAMERA_SMOOTH_BLUR = 0.0;

    protected float m_SmoothBlur;

    void CameraEffects()
    {

    }

    // Postprocess effects materials.
	void init()
	{

	}

    // Function used to apply NVG grain effects on a player.
    //static void setNVGEffect(float sharpness, float grain_size)
    //{
    //    Material matHDR = g_Game.GetWorld().GetMaterial("Graphics/Materials/postprocess/filmgrainNV");
    //    SHARPNESS = sharpness;
    //    GRAIN_SIZE = grain_size;

    //    if(matHDR)
    //    {
    //        matHDR.SetParam("Sharpness", SHARPNESS);
    //		    matHDR.SetParam("GrainSize", GRAIN_SIZE);
    //    }
    //}

    // Function used to change Chromatic Aberration X value.
    static void changeChromaX(int value)
    {
    	Material chroma = g_Game.GetWorld().GetMaterial("graphics/materials/postprocess/chromaber");
        CHROMABERX = value;

        if(chroma)
        {
            chroma.SetParam( "PowerX", CHROMABERX );
        }
    }

    // Function used to change Chromatic Aberration Y value.
    static void changeChromaY(int value)
    {
    	Material chroma = g_Game.GetWorld().GetMaterial("graphics/materials/postprocess/chromaber");
        CHROMABERY = value;

        if(chroma)
        {
            chroma.SetParam( "PowerY", CHROMABERY );
        }
    }

    // Sets the exposure of the players camera.
    static void setExposure(int value)
    {
        EXPOSURE = (value * 0.1) - 5.0;
	    g_Game.SetEVUser(EXPOSURE);
    }

    // Function used to change radial blur effect on X-axis. 
    // Intensity value between 0-100. 0 been least instense, 100 most intense.
	static void changeRadBlurXEffect(int intensity) 
	{
		Material radialBlur = g_Game.GetWorld().GetMaterial("Graphics/Materials/postprocess/radialblur");
		RADBLURX = (intensity * 0.01);

		if(radialBlur)
		{
            radialBlur.SetParam("PowerX", RADBLURX);
		}
	}
 
    // Function used to change radial blur effect on the Y-axis.
    // Intensity value between 0-100. 0 been least instense, 100 most intense.
	static void changeRadBlurYEffect(int intensity) 
	{
		Material radialBlur = g_Game.GetWorld().GetMaterial("Graphics/Materials/postprocess/radialblur");
		RADBLURY = (intensity * 0.01);

		if(radialBlur)
		{
            radialBlur.SetParam("PowerY", RADBLURY);
		}
	}

    // Function used to change radial blur offset effect on X-axis. 
    // Intensity value between 0-100. 0 been least instense, 100 most intense.
	static void changeRadBlurXOffsetEffect(int intensity) 
	{
		Material radialBlur = g_Game.GetWorld().GetMaterial("Graphics/Materials/postprocess/radialblur");
		RADBLUROFFX = (intensity * 0.01);

		if(radialBlur)
		{
            radialBlur.SetParam("OffsetX", RADBLUROFFX);
		}
	}

    // Function used to change radial blur offset effect on the Y-axis.
    // Intensity value between 0-100. 0 been least instense, 100 most intense.
	static void changeRadBlurYOffsetEffect(int intensity) 
	{
		Material radialBlur = g_Game.GetWorld().GetMaterial("Graphics/Materials/postprocess/radialblur");
		RADBLUROFFY = (intensity * 0.01);

		if(radialBlur)
		{
            radialBlur.SetParam("OffsetY", RADBLUROFFY);
		}
	}

    // Function used to change rotation blur depth. 
    // Intensity value between 0-100. 0 been least instense, 100 most intense.
	static void changeRotationBlurPower(int intensity) 
	{
		Material rotationBlur = g_Game.GetWorld().GetMaterial("Graphics/Materials/postprocess/rotblur");
		ROTBLUR = 0.5 * (intensity * 0.01);

        if(rotationBlur)
        {
            rotationBlur.SetParam("Power", ROTBLUR);
        }
	}

    // Function used to change rotation blur depth. 
    // Intensity value between 0-100. 0 been least instense, 100 most intense.
	static void changeRotationBlurDepth(int intensity) 
	{
		Material rotationBlur = g_Game.GetWorld().GetMaterial("Graphics/Materials/postprocess/rotblur");
		MINDEPTH = 2.5 * (intensity * 0.01);

		if(rotationBlur)
		{
            rotationBlur.SetParam("MinDepth", MINDEPTH);
		}
	}

    // Function used to change rotation blur max depth. 
    // Intensity value between 0-100. 0 been least instense, 100 most intense.
	static void changeRotationBlurMaxDepth(int intensity) 
	{
		Material rotationBlur = g_Game.GetWorld().GetMaterial("Graphics/Materials/postprocess/rotblur");
		MAXDEPTH = (intensity * 0.1);

		if(rotationBlur)
		{
            rotationBlur.SetParam("MaxDepth", MAXDEPTH);
		}
	}

    // Function used to change the strength of the vignette effect.
    // Intensity value between 0-100. 0 been least instense, 100 most intense.
	static void changeVignette(int intensity) 
	{
		Material materialColors = g_Game.GetWorld().GetMaterial("graphics/gaterials/postprocess/glow");
		VIGNETTE = (intensity * 0.02);

		if(materialColors)
		{
		    materialColors.SetParam("Vignette", VIGNETTE);
		}
	}

    // Function used to change the Red color of the vignette effect.
    // Intensity value between 0-100. 0 been least instense, 100 most intense.
	static void changeVignetteColorRGB(int R, int G, int B) 
	{
		Material materialColors = g_Game.GetWorld().GetMaterial("Graphics/Materials/postprocess/glow");
		VARGB[0] = R;
		VARGB[1] = G;
		VARGB[2] = B;

		if(materialColors)
		{
            materialColors.SetParam("VignetteColor", VARGB);
		}
	}

    // Function used to change the RGB color of the overlay.
    // Intensity value between 0-100. 0 been least instense, 100 most intense.
	static void changeOverlayColorRGB(int R, int G, int B, int overlay) 
	{
		Material materialColors = g_Game.GetWorld().GetMaterial("Graphics/Materials/postprocess/glow");
		CARGB[0] = R;
		CARGB[1] = G;
		CARGB[2] = B;
		CARGB[3] = ((overlay * 0.05) - 4.0);;


		if(materialColors)
		{
        	materialColors.SetParam("OverlayColor", CARGB);
		    materialColors.SetParam("OverlayFactor", CARGB[3]);
		}
	}

    // Function used to change Hue of the screen. 
    // Intensity value between 0-1000.
	static void changeHue(float intensity) 
	{
		Material materialColors = g_Game.GetWorld().GetMaterial("graphics/materials/postprocess/glow");
		HUESHIFT = (intensity * 0.1) - 5.0;

		if(materialColors)
		{
		    materialColors.SetParam( "Saturation", HUESHIFT);
		}
	}

	// Temporarily reset all PPE materials to defaults without changing the tracked state.
	// Used when entering admin free camera so drug visuals don't affect the bird's eye view.
	static void SuspendDrugPPE()
	{
		Material glow = g_Game.GetWorld().GetMaterial("graphics/materials/postprocess/glow");
		Material chromaber = g_Game.GetWorld().GetMaterial("graphics/materials/postprocess/chromaber");
		Material radialBlur = g_Game.GetWorld().GetMaterial("Graphics/Materials/postprocess/radialblur");
		Material rotationBlur = g_Game.GetWorld().GetMaterial("Graphics/Materials/postprocess/rotblur");
		
		if (glow)
			glow.SetParam("Saturation", 1.0);
		if (chromaber)
		{
			chromaber.SetParam("PowerX", 0.0);
			chromaber.SetParam("PowerY", 0.0);
		}
		if (radialBlur)
		{
			radialBlur.SetParam("PowerX", 0.0);
			radialBlur.SetParam("PowerY", 0.0);
		}
		if (rotationBlur)
			rotationBlur.SetParam("Power", 0.0);
	}

	// Re-apply PPE from the tracked static values after returning from free camera.
	static void RestoreDrugPPE()
	{
		Material glow = g_Game.GetWorld().GetMaterial("graphics/materials/postprocess/glow");
		Material chromaber = g_Game.GetWorld().GetMaterial("graphics/materials/postprocess/chromaber");
		Material radialBlur = g_Game.GetWorld().GetMaterial("Graphics/Materials/postprocess/radialblur");
		Material rotationBlur = g_Game.GetWorld().GetMaterial("Graphics/Materials/postprocess/rotblur");
		
		if (glow)
			glow.SetParam("Saturation", HUESHIFT);
		if (chromaber)
		{
			chromaber.SetParam("PowerX", CHROMABERX);
			chromaber.SetParam("PowerY", CHROMABERY);
		}
		if (radialBlur)
		{
			radialBlur.SetParam("PowerX", RADBLURX);
			radialBlur.SetParam("PowerY", RADBLURY);
		}
		if (rotationBlur)
			rotationBlur.SetParam("Power", ROTBLUR);
	}
};