//Cracked by Roath
// by snowcat

inherit ROOM;

void create ()
{
  set ("short", "������ջ");
  set ("long", @LONG

��ջ����˼��ź�ľ���ӣ�Χ�����ӷ��˼������ʡ��˴�����������
����Ʈ�Ų��㡣��ǽ�ǹ�̨����������˴�С��ͬ�Ĳ�Ͳ��ޡ�����
����ͨ���ͷ��

LONG);

  set("exits", ([
    "east" : __DIR__"shun5",
  ]));
  set("objects", ([ /* sizeof() == 2 */
"/obj/boss/kaifeng_chaniang" : 1,
  ]));
  set("resource", ([ /* sizeof() == 1 */
    "water" : 1,
  ]));
  set("valid_startroom", 1);
  setup();
}

