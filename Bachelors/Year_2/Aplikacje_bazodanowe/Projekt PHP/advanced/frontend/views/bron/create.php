<?php

use yii\helpers\Html;


/* @var $this yii\web\View */
/* @var $model common\models\Bron */

$this->title = Yii::t('app', 'Stwórz broń');
$this->params['breadcrumbs'][] = ['label' => Yii::t('app', 'Bronie'), 'url' => ['index']];
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="bron-create">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
        'rodzaje' => $rodzaje,
        'obrazenia' => $obrazenia,
    ]) ?>

</div>
