// by HAPP@YSZZ

inherit ROOM;
int block_cmd(string);
void create ()
{
        set ("short", "���������Ƶ��Ϲ�");
        set ("long", @LONG
 ����ʵ����׼ʱ�ģ���ʱ�����ǾͿ�����֪�������˸����ˣ�������������Լ�ᶼ��׼ʱ��
 
LONG);


        set("exits", ([
        "southup"    :       __DIR__"sz2jx1",
        "westdown"  :       __DIR__"jn2sz2",        
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/shuangzi" : 1,
        ]));
        set("outdoors", "12gong");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( present("xiaoji jun") && dir == "southup" )
        return notify_fail("Ф��������Ц:�ȹ��������˵��\n");
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
