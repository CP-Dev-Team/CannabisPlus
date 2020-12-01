class CPTransactionCallBack : RestCallback
{
    string Status = "Pending";
    string ID = "";
    float Value;
    string Element;
    
    override void OnError(int errorCode) {
    
    };
    
    override void OnTimeout() {
    
    };
    
    override void OnSuccess(string data, int dataSize) {
    
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
        string jsonString = JsonFileLoader<UApiTransaction>.JsonMakeData(this);;
        return jsonString;
    }
    
};

class CPApiSilentCallBack : RestCallback
{
    override void OnError(int errorCode) {};
    override void OnTimeout() {};
    override void OnSuccess(string data, int dataSize) {};
};