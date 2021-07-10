<?php

namespace App\Http\Controllers;

use App\Models\Article;
use App\Models\User;
use Illuminate\Http\Request;

class ArticleController extends Controller
{
    public function show(){
       # dd(User::find(8)->articles()->first());
        dd(Article::find(8)->user()->first());
    }
}
