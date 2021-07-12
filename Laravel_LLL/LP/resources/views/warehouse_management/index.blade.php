<!DOCTYPE html>
<html lang="en">
<head>
    <title>مدیریت انبارها</title>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
</head>
<body>

<div class="container">
    <h2>منوی اصلی </h2>
    <img align="right" src="img/th1.jpg" width="120" height="120">

    <a href="{{route('warehouses.show')}}" class="btn btn-info btn-lg active" role="button" aria-pressed="true">لیست انبارها</a>
    <a href="{{route('products.show')}}" class="btn btn-info btn-lg active" role="button" aria-pressed="true">لیست محصولات</a>
    <a href="{{route('product.create')}}" class="btn btn-success btn-lg active" role="button" aria-pressed="true">افزودن محصول</a>
    <a href="{{route('warehouse.create')}}" class="btn btn-success btn-lg active" role="button" aria-pressed="true">افزودن انبار</a>

    <hr>
    <hr>
    <hr>

@if($errors->any())
    <div class="alert-danger">
        <ul>
            @foreach($errors->all() as $i)
                <li>{{$i}}</li>
            @endforeach
        </ul>
        @endif
    </div>

@yield('content')




</div>

</body>
</html>
