// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "�ڶ������Ƶ�����");
         set ("long", @LONG
  ����������������ϲ���Ķ��������������ʵ�����ѣ�������������Ƕ�����ʵҡβ�ͣ�
  ��������������������������������겻����ò�������ԣ����Գ�����˵��Ȯ�����Ĺ��£�
  ���Է�����ȮΧ�����ˣ�һ���ǻ��ˣ�һ��Ҫ���������ʴˡ�������������Ȯ�л�����ɡ�

LONG);


        set("exits", ([
        "westup"    :       __DIR__"jn2sz1",
        "northdown"  :       __DIR__"by2jn2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/jinniu" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("xiaogou jun") && dir == "westup" )
        return notify_fail("ФȮ����Ц��:�ȹ��������˵��\n");
        return ::valid_leave(me, dir);
}

void init()
{
    add_action("block_cmd", "", 1);
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "recall") return 1;
    return 0;
}
