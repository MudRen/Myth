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
       "south" : "/d/milin/qy/d2",   
       "north" : "/d/milin/qy/d3",   
       "up" : "/d/milin/qy/d4",   
       "northeast" : "/d/milin/qy/d5",   
       "east" : "/d/milin/qy/d6",   
       "west" : "/d/milin/qy/d7",   
       "down" : "/d/milin/qy/d8",   
       "southeast" : "/d/milin/qy/d9",   
       "enter" : "/d/milin/qy/d10",   
]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/milin/npc/long2" : 2, 
        ]));

  set("no_clean_up", 1);

  setup();
}
