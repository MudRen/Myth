//tianpei ����
//by calvin and leox ��ͬ����
//��Ȩ����,δ����ɲ��÷�¼

inherit ROOM;
void create ()
{
        set ("short", "С·");
        set ("long", @LONG
����һ������ϡ�ٵĻĽ�Ұ·,ƽʱ·�Ϻ��ټ�����·��.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "east" : "/d/calvin/tianpeng/luw2",    
//       "west" : "/d/calvin/tianpeng/pomiao",    
       "north" : "/d/leox/tianpeng/ye1",    
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
