<?php

use yii\helpers\Html;


/* @var $this yii\web\View */
/* @var $model common\models\Rasa */

$this->title = Yii::t('app', 'Stwórz rasę');
$this->params['breadcrumbs'][] = ['label' => Yii::t('app', 'Rasy'), 'url' => ['index']];
$this->params['breadcrumbs'][] = $this->title;
?>
<div class="rasa-create">

    <h1><?= Html::encode($this->title) ?></h1>

    <?= $this->render('_form', [
        'model' => $model,
    ]) ?>

</div>
