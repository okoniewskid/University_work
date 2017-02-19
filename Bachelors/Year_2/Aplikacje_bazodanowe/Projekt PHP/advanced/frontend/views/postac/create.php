<?php

use yii\helpers\Html;


/* @var $this yii\web\View */
/* @var $model common\models\Postac */

$this->title = Yii::t('app', 'Stwórz postać');
$this->params['breadcrumbs'][] = ['label' => Yii::t('app', 'Postacie'), 'url' => ['index']];
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="postac-create">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
        'rasy' => $rasy,
        'bronie' => $bronie,
        'pancerze' => $pancerze,
    ]) ?>

</div>
