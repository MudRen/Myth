//Cracked by Roath
// create by snowcat jan 21 1998


inherit ROOM;

void create ()
{
  set ("short", "��ٵ�");
  set ("long", @LONG

һ��������ֱ�Ĵ�ٵ���ƽԭ���ɶ�����ԶԶ�����ӿ�������
��ƽ�����ݵ���ʮ���ۡ���ٵ��Ķ���ͨ��Զ����

LONG);

  set("exits", ([
        "west" : __DIR__"east2",
        "east" : __DIR__"east4",
      ]));
  set("outdoors", __DIR__);

  if(random(2))
          set("objects", ([ "/d/obj/weapon/throwing/shi.c" : 1, ]));
    else
	    set("objects", ([ "/d/obj/weapon/throwing/smallshi.c" : 1, ]));

  setup();
}


