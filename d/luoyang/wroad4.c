inherit ROOM;

void create()
{
        set("short", "��µ�");
        set("long", @LONG
����һ����խ����ʯ��ֵ���������ͷ���졣��ס���������ϵĴ�
����һЩ������ʿ�����ϰ��֮�缫ʤ�������ɼ�����֮�ˣ���ݣ��䳡��
�ھ�Ҳ�ȱȽ��ǣ�Ϊ�˰�ȫ���ٸ������ﲼ���˹ٱ������߾��Ǳ�Ӫ���ڣ�
���Ϸ����ס�ŵ�ʱ�������ֽ����ң��������������Ĵ��˼ң�����
�����������Ժգ������ǰ���������������ʿ�Ⱥ�ݷá�
LONG);
        set("outdoors", "luoyang");
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"wroad3",
                "south" : __DIR__"jiaochang",
                "north" : __DIR__"bingyindamen",
                "west" : __DIR__"wroad7",
        ]));

        setup();
        replace_program(ROOM);
}

