// Room: /u/mimi/zhuziguo/backyard  snowcat moved to /d/qujing/wuji
inherit ROOM;

void create ()
{
  set ("short", "��Ժ");
  set ("long", @LONG

��Ժ����������Ժ���￪��һ���԰�ӣ����Ÿ����߲˹Ϲ�������
��һƬ����һ���ټ��ӣ�һЩ˵�������ֵ������������棬���Ż�
ɫ��С����

LONG);

  set("outdoors", __DIR__"");                         
  set("exits", ([ /* sizeof() == 1 */
    "south" : __DIR__"eastroom",
  ]));

  setup();
}

