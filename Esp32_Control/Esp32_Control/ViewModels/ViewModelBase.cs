using CommunityToolkit.Mvvm.ComponentModel;

namespace Esp32_Control.ViewModels;

public partial class ViewModelBase : ObservableObject
{
    protected readonly Store _store;

    protected ViewModelBase(
        Store store
    ){
        _store = store;
    }
}
