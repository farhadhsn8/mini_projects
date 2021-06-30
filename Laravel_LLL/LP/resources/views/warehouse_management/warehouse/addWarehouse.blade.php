
@extends('warehouse_management.index')

@section('content')

<h1 class="pageLables">افزودن انبار جدید </h1>
<div class="row">
    <div class="col-lg-8 col-lg-offset-2" >
        <section class="panel">

            <div class="panel-body">
                <form role="form" action="{{route('warehouse.store')}}" method="POST">
                    @csrf
                    <div class="form-group">
                        <label for="exampleInputEmail1">نام انبار  </label>
                        <input type="text" name="name" class="form-control" placeholder="نام انبار را وارد کنید">
                    </div>

                    <div class="form-group">
                        <label for="exampleInputEmail1">آدرس   </label>
                        <input type="text" name="address" class="form-control" placeholder="آدرس انبار را وارد کنید">
                    </div>

                    <button type="submit" name="btn" class="btn btn-info">افزودن</button>
                </form>

            </div>
        </section>
    </div>
</div>
@endsection
