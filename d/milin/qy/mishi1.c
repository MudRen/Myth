// ���ֱ��� by Calvin

inherit ROOM;

void create()
{
  set ("short", "���ֱ���");
  set ("long", @LONG
���������ֵ������ܵĵط�---���ֱ���,��˵����ı�������Ů����������ʹ����,
���Ǻ���һֱû��ô�ù�,�վ��쳤Ҳ��������Щ�����Ĵ��ڡ�
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "south" : "/d/milin/qy/u2",   
       "north" : "/d/milin/qy/u3",   
       "up" : "/d/milin/qy/u4",   
       "northeast" : "/d/milin/qy/u5",   
       "east" : "/d/milin/qy/u6",   
       "west" : "/d/milin/qy/u7",   
       "down" : "/d/milin/qy/u8",   
       "southeast" : "/d/milin/qy/u9",   
       "enter" : "/d/milin/qy/u10",   
]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/milin/npc/long1" : 2, 
       "/d/npc/obj/whip" : 1,
        ]));

  set("no_clean_up", 1);

  setup();
}
