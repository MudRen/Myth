//Cracked by Roath
// Room: /d/nanhai/restroom
inherit ROOM;
inherit "/d/wiz/no_get";

void create ()
{
  set ("short", "��Ϣ��");
  set ("long", @LONG

����������ɽ����Ϣ�ң�������յ�����ʲôҲû�У���֪����
ɽ���˵���������ô��˯���ġ�
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"zoulang2",
]));
  set("no_fight", 1);
  set("light_up", 1);
  set("no_magic", 1);
  set("sleep_room", 1);

  setup();
}
