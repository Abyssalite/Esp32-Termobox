
using Websocket.Client;


namespace Esp32_Control.ViewModels;

public partial class MainViewModel : ViewModelBase
{    
    //private WebsocketClient? _client;

    private string _address;
    public string Address
    {
        get => _address;
        set
        {
            if (value != null)
            {
                _address = value;
                _store.Address = _address;
            }
        }
    }

    private string _status;
    public string Status
    {
        get => _status;
        set
        {
            if (value != null)
            {
                _status = value;
                _store.Status = _status;

            }
        }
    } 

    public MainViewModel(
        Store store
    ):base(store)
    {
        _status = "Disconnected";
        _address = "123";
    }
}
