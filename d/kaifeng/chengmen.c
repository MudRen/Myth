//Cracked by Roath
// create by snowcat jan 21 1998

inherit ROOM;

void create ()
{
  set ("short", "�������");
  set ("long", @LONG

һ���߸ߵ�����ʯǽ��¥�����������������չ��������һ������
������Ŷ��ﴩ�����������ǳ���������ͨ��Զ����������վ��
��һЩ��ʿ������ػ����ſ���ǡ�

LONG);

  set("exits", ([
        "west" : __DIR__"east5",
        "east" : __DIR__"chen1",
      ]));

  set("objects", 
      ([
         __DIR__"npc/wujiang" : 1,
         __DIR__"npc/bing" : 3,
      ]));
  set("outdoors", __DIR__);

  setup();
}


