
@extends('warehouse_management.index')

@section('content')

<h1 class="pageLables">آپدیت انبار  </h1>
<div class="row">
    <div class="col-lg-8 col-lg-offset-2" >
        <section class="panel">

            <div class="panel-body">
                <form role="form" action="{{route('warehouse.update',$warehouse->id)}}" method="POST">
                    @csrf
                    @method('put')
                    <div class="form-group">
                        <label for="exampleInputEmail1">نام انبار  </label>
                        <input type="text" name="name" class="form-control" value="{{$warehouse->name}}" placeholder="نام انبار را وارد کنید">
                    </div>

                    <div class="form-group">
                        <label for="exampleInputEmail1">آدرس   </label>
                        <input type="text" name="address" class="form-control" value="{{$warehouse->address}}" placeholder="آدرس انبار را وارد کنید">
                    </div>

                    <button type="submit" name="btn" class="btn btn-info">آپدیت</button>
                </form>

            </div>
        </section>
    </div>
</div>
@endsection
