//Cracked by Roath
// room: /d/moon/xiaoyuan.c

#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_stand(string temp2);
int do_sit(string temp3);

void create ()
{
  set ("short", "����¥");
  set ("long", @LONG

һ������ı���ɫС��¥, ���滷ˮ, ����һ����ˮ���ر߻���ӳˮ����
��������ϼ�������㣬�кɵ�㡣һ��ƽ̨��ˮ��������ʯΪ��������Ϊ
ש��̨�澧Ө��͸��ƽ���羵�������к��������է���ǻ�Ӱ��ϸ����֪
�Ǻ�ɫ����͸��ʯ�����·���˿˿Ѫ��һ�㡣���������һ�����, ��
�滹�а�ֲ��壮������տտյ���, ֻ�����������Σ��˴��ľ����ˣ�
�ƺ���һ�����õľ���֮����
LONG);

  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"road3",
  "south" : __DIR__"lotuspond",
  "up" : __DIR__"bedroom",
]));
  set("no_magic", 1);

  setup();
}
