inherit ROOM;

void create()
{
        set("short", "��µ�");
        set("long", @LONG
����һ����խ����ʯ��ֵ���������ͷ���졣������������������
�Ĺ㳡�ˡ���ס���������ϵĴ���һЩ������ʿ�����ϰ��֮�����ʤ��
�����ɼ�����֮�ˣ���ݣ��䳡���ھ�Ҳ�ȱȽ��ǣ�Ϊ�˰�ȫ���ٸ�����
�ﲼ���˹ٱ��������Ǹ������˵�ס���������޷��������Ǻպ���������
��Ǯׯ��
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                  "east" : __DIR__"center",
                  "north" : __DIR__"xinluofang",
                  "south" : __DIR__"huqing",
                  "west" : __DIR__"wroad2",
        ]));
        set("objects", ([
                "/d/city/npc/xunluobing" : 1,
        ]));
        setup();
        replace_program(ROOM);
}

