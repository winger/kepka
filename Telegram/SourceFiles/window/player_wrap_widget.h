#pragma once

#include "media/player/media_player_widget.h"
#include "ui/effects/widget_slide_wrap.h"

namespace Ui {
class PlainShadow;
} // namespace Ui

namespace Window {

class PlayerWrapWidget : public Ui::WidgetSlideWrap<Media::Player::Widget> {
	using Parent = Ui::WidgetSlideWrap<Media::Player::Widget>;

public:
	PlayerWrapWidget(QWidget *parent, Fn<void()> updateCallback);

	void updateAdaptiveLayout() {
		updateShadowGeometry();
	}
	void showShadow() {
		entity()->showShadow();
	}
	void hideShadow() {
		entity()->hideShadow();
	}
	int contentHeight() const {
		return qMax(height() - st::lineWidth, 0);
	}

protected:
	void resizeEvent(QResizeEvent *e) override;

private:
	void updateShadowGeometry();
};

} // namespace Window
