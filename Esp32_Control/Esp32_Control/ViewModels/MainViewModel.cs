
using System;
using System.Windows.Input;
using CommunityToolkit.Mvvm.Input;

namespace Esp32_Control.ViewModels;

public partial class MainViewModel : ViewModelBase
{    
    public ICommand AddDeviceCommand { get; }

    public MainViewModel(
        Store store
    ):base(store)
    {
        AddDeviceCommand = new RelayCommand(addDevice);
    }

    void addDevice()
    {
        Console.WriteLine("test");
    }
}
