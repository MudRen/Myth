inherit ROOM;

void create()
{
        set("short", "��µ�");
        set("long", @LONG
����һ����խ����ʯ��ֵ���������ͷ���졣��ס���������ϵĴ�
����һЩ������ʿ�����ϰ��֮�缫ʤ�������ɼ�����֮�ˣ���ݣ��䳡��
�ھ�Ҳ�ȱȽ��ǣ�Ϊ�˰�ȫ���ٸ������ﲼ���˹ٱ�������������ī�ͳ�
���ݼ��Ŀ���������һЩ���뽭�����˳���������ݡ�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"wroad1",
                "north" : __DIR__"kongmiao",
                "south" : __DIR__"wuguan",
                "west" : __DIR__"wroad3",
        ]));

        setup();
        replace_program(ROOM);
}

