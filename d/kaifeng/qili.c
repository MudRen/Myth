//Cracked by Roath
// by snowcat

inherit ROOM;

void create ()
{
  set ("short", "�����¥");
  set ("long", @LONG

��¥�������ߣ��������һ�Ҵ����ƣ��������¥����¥������Ŵ�
��ľ���ӣ������治ʱ��ɢ����һ���󷹲�����㡣��¥�������Ǵ�
�֡�

LONG);

  set("exits", ([
    "west" : __DIR__"yao5",
  ]));
  set("objects", ([ /* sizeof() == 2 */
"/obj/boss/kaifeng_hai" : 1,
  ]));
  set("resource", ([ /* sizeof() == 1 */
    "water" : 1,
  ]));
  setup();
}

