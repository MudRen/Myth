// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "�ƹ�");
  set ("long", @LONG

�ƹ�Ϊһ˫��Сľ¥�����ſڵľ���������ժ��������ľ����
ľ�β��øɸɾ�������̨������һ���ӣ����У�����Ƽ��꣬
��ѹ��衱�˸����֡�
    
LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao4",
      ]));
  set("objects", ([
        __DIR__"npc/sg3" : 1,
        __DIR__"obj/tea" : 2,
      ]));
  setup();
}

