// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "��ñ��");
  set ("long", @LONG

��ñ���������ǽ�������д�С���������ĸ���һ��������д
�ţ�������۸����ñ�������ߡ����������Ͽտ���Ҳ������
һ��С�ƣ���������ʩ�Ƽ��꣬�Ѿ��Ҳ���
    
LONG);

  set("exits", ([
        "south"    : __DIR__"jiedao5",
      ]));
  set("objects", ([
        __DIR__"npc/sg2"    : 1,
      ]));
  setup();
}

