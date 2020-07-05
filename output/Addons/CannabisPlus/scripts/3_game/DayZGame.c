modded class DayZGame {

    protected ref CannabisPlusConfig CPConfig;

    ref CannabisPlusConfig GetCannabisPlusConfig() {
        return CPConfig;
    }

    void SetCannabisPlusConfig(ref CannabisPlusConfig config) {
        CPConfig = config;
    }
}