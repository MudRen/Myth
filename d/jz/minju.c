//Cracked by Roath

inherit ROOM;
void create ()
{
  set ("short", "���");
  set ("long", @LONG

    ����С��һ�䷿�ӣ���������һ�鷢�Ƶ��Ű壬���������ŵģ�
����̨���Ѿ��������ˡ���ǰֻ��һλ���ߣ�����������˳���Զ��
�ˡ�
LONG);

  set("exits", ([
        "east"         : __DIR__"dingan-2",
      ]));
  set("objects", ([
      __DIR__"npc/laozhe"  : 1,
      ]));
  setup();
}
