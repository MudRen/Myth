//Cracked by Roath
// /d/jz/in.c
// ����֮�� 1.0
// by happ@YSZZ 200.04.02

inherit ROOM;
void create()
{
  set ("short", "����");
  set ("long", @LONG

����һ�����õĺܵ���ķ��䣬�辰�����磬���������˾��ð�
�ĺܺ��ʡ�һ�߽���������ŵ�һ�����㣬��ȻҲֻ�йٻ��˼�
�Ż�����˵İ��衣
LONG);

  set("exits", ([ /* sizeof() == 1 */
         "east" : __DIR__"datang",
        ]));
  set("objects", ([
        __DIR__"npc/yin" : 1,
        ]));
        setup();
}
int valid_leave(object me, string dir)
{

        if (objectp(present("liu hong", environment(me)))
         || objectp(present("li biao", environment(me))) )
        return notify_fail("�����ڲ�����ȥ��\n");
        return ::valid_leave(me, dir);
}
