
@extends('warehouse_management.index')
@section('content')
<h1 class="pageLables">افزودن محصول جدید </h1>
<div class="row">
    <div class="col-lg-8 col-lg-offset-2" >
        <section class="panel">

            <div class="panel-body">
                <form role="form" method="post">
                    <div class="form-group">
                        <label for="exampleInputEmail1">نام محصول  </label>
                        <input type="text" name="frm[name]" class="form-control" placeholder="نام محصول را وارد کنید">
                    </div>


                    <div class="form-group">
                        <label for="exampleInputPassword1">انبار </label>
                        <select multiple class="form-control input-lg m-bot15" name="frm[warehouse_id][]"   aria-label="multiple select example">

                                <option value=''> bmbmbmbmb  </option>

                        </select>
                    </div>

                    <button type="submit" name="btn" class="btn btn-info">افزودن</button>
                </form>

            </div>
        </section>
    </div>
</div>
@endsection
