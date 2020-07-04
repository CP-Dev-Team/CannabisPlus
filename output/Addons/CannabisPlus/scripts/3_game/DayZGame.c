// store the config values here so that they can be accessed
// "globally" and synced with the client and server
modded class DayZGame {

    protected ref CannabisPlusConfig CPConfig;

    ref CannabisPlusConfig GetCannabisPlusConfig() {
        return CPConfig;
    }

    void SetCannabisPlusConfig(ref CannabisPlusConfig config) {
        CPConfig = config;
    }
}