// Room: dongnei  create by smile 12/10/1998
inherit ROOM;

void create()
{
  set ("short", "����");
  set ("long", @LONG

  ����͵��˰׹Ƕ����ˡ�
   �����׻����Ƶģ������������յ������һ����һ��ڣ�
���²����˹Ǽܣ���֨��֨�ģ�����˸���ս��
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "enter" : __DIR__"baigudong",
    "out" : __DIR__"dongkou",
    "west": __DIR__"wangukeng",
    "east": __DIR__"xuechi",
  ]));
  set("outdoors", __DIR__"");                   
  setup();
}
