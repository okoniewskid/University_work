<?php
use yii\helpers\Html;
use yii\bootstrap\Nav;
use yii\bootstrap\NavBar;
use yii\widgets\Breadcrumbs;
use frontend\assets\AppAsset;
use frontend\widgets\Alert;

/* @var $this \yii\web\View */
/* @var $content string */

AppAsset::register($this);
?>
<?php $this->beginPage() ?>
<!DOCTYPE html>
<html lang="<?= Yii::$app->language ?>">
<head>
    <meta charset="<?= Yii::$app->charset ?>">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <?= Html::csrfMetaTags() ?>
    <title><?= Html::encode($this->title) ?></title>
    <?php $this->head() ?>
</head>
<body>
    <?php $this->beginBody() ?>
    <div class="wrap">
        <?php
            NavBar::begin([
                'brandLabel' => 'Karty postaci',
                'brandUrl' => Yii::$app->homeUrl,
                'options' => [
                    'class' => 'navbar-inverse navbar-fixed-top',
                ],
            ]);
            $menuItems = [
                ['label' => 'Strona domowa', 'url' => ['/site/index']],
                ['label' => 'Administracja', 'items' =>[
                 ['label' => 'Postacie', 'url' => ['/postac/index']],
                 ['label' => 'Rasy', 'url' => ['/rasa/index']],
                 ['label' => 'Bronie', 'url' => ['/bron/index']],
                 ['label' => 'Pancerze', 'url' => ['/pancerz/index']],
                 ['label' => 'Obrazenia', 'url' => ['/obrazenia/index']],
                 ['label' => 'Rodzaje obrazen', 'url' => ['/rodzaj/index']],
                ]],
            ];
           /* if (Yii::$app->user->isGuest) {
                $menuItems[] = ['label' => 'Rejestracja', 'url' => ['/site/signup']];
                $menuItems[] = ['label' => 'Logowanie', 'url' => ['/site/login']];
            } else {
                $menuItems[] = [
                    'label' => 'Wyloguj (' . Yii::$app->user->identity->username . ')',
                    'url' => ['/site/logout'],
                    'linkOptions' => ['data-method' => 'post']
                ];
            }*/
            echo Nav::widget([
                'options' => ['class' => 'navbar-nav navbar-right'],
                'items' => $menuItems,
            ]);
            NavBar::end();
        ?>

        <div class="container">
        <?= Breadcrumbs::widget([
            'links' => isset($this->params['breadcrumbs']) ? $this->params['breadcrumbs'] : [],
        ]) ?>
        <?= Alert::widget() ?>
        <?= $content ?>
        </div>
    </div>
    
    <footer class="footer">
        <div class="container">
        <p class="pull-left">&copy; Projekcik <?= date('Y') ?></p>
        <p class="pull-right"><?= Yii::powered() ?></p>
        </div>
    </footer>
    
    <?php $this->endBody() ?>
</body>
</html>
<?php $this->endPage() ?>