class CPRestApi
{    
    static protected string m_BaseUrl = CPTOKENS.URL;
    static protected string m_AuthToken = CPTOKENS.AUTH;

    static RestApi Api()
    {
        RestApi clCore = GetRestApi();
        if (!clCore)
        {
            clCore = CreateRestApi();
            clCore.SetOption(ERestOption.ERESTOPTION_READOPERATION, 15);
        }
        return clCore;
    }
    
    static void Post(string url, string jsonString = "{}", ref RestCallback UCBX = NULL)
    {
        if (!UCBX){
            UCBX = new ref CPApiSilentCallBack
        }
        RestContext ctx =  Api().GetRestContext(url);
        ctx.SetHeader("application/json");
        ctx.POST(UCBX , "", jsonString);
        Print("Post" + url + jsonString);
    }

    static string BaseUrl(){
        return m_BaseUrl;
    }
    
    static string AuthToken(){
        return m_AuthToken;
    }
    
    static void Increment(string element, float value = 1) {
        Print( "Increment" + element );
            ref RestCallback UCBX = new ref CPTransactionCallBack;
        
        
        string url = BaseUrl() + "Gobals/Transaction/CannabisPlus/" + AuthToken();
        
        ref CPApiTransaction transaction = new ref CPApiTransaction(element, value);
        
        if ( element && transaction && UCBX){
            Post(url,transaction.ToJson(),UCBX);
        } else {
            Print("[CPApi] [Api] Error Updating " +  element);
        }
    }    
    
};

static ref CPRestApi g_CPRestApi;

static ref CPRestApi CPApi()
{
    if ( !g_CPRestApi )
    {
        Print("[CPApi] Init");
        g_CPRestApi = new ref CPRestApi;
    }

    return g_CPRestApi;
};