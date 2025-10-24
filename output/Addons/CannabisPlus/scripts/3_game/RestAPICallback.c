class CPTransactionCallBack : RestCallback
{
    string Status = "Pending";
    string ID = "";
    float Value;
    string Element;
    
    override void OnError(int errorCode) {
    CPDebugPrint("Transaction Error");
    };
    
    override void OnTimeout() {
    CPDebugPrint("Transaction Timeout");
    };
    
    override void OnSuccess(string data, int dataSize) {
    CPDebugPrint("Transaction Success" + data);    
    };
};

class CPApiTransaction
{
    string Element;
    float Value;
    
    void CPApiTransaction(string element, float value){
        Element = element;
        Value = value;
    }
    
    string ToJson(){
        string jsonString = JsonFileLoader<CPApiTransaction>.JsonMakeData(this);;
        return jsonString;
    }
    
};

class CPApiSilentCallBack : RestCallback
{
    override void OnError(int errorCode) {};
    override void OnTimeout() {};
    override void OnSuccess(string data, int dataSize) {};
};