// created by angell 1/1/2001
// room: /d/qujing/huangfeng/inn.c

inherit ROOM;

void create()
{
  set ("short", "С�Ƶ�");
  set ("long", @LONG

ɽǰС�꣬�������������˶�ϲ�����������һ������Ȼ��
���Ǻܴ󣬾�Ӫ�Ķ�������ʲô�ر�õĻ�ɫ���������ɽ
Ұ��֮��ȴ���ѵ�֮�������Կ��˺ܶࡣһ�����ǰǰ���
��æ�š�

LONG);
set("exits", ([ /* sizeof() == 1 */
"north" : __DIR__"tulu1",
]));
set("objects", ([
                __DIR__"npc/xiaoer": 1, ]) );

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
