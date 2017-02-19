<?php

use yii\helpers\Html;


/* @var $this yii\web\View */
/* @var $model common\models\Pancerz */

$this->title = Yii::t('app', 'Stwórz pancerz');
$this->params['breadcrumbs'][] = ['label' => Yii::t('app', 'Pancerze'), 'url' => ['index']];
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="pancerz-create">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
        'rodzaje' => $rodzaje,
    ]) ?>

</div>
