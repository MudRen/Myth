inherit ROOM;

void create()
{
        set("short", "��ԡ��");
        set("long", @LONG
�����������ڣ��������ƣ�һ�ж�������֮�У����к����и��ܴ��
ԡ�أ�һЩ���������澡��������ţ�΢�����ԣ�����������������۾�
��ϸһ����ԭ������Щ����ү�ǣ�û��û����
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"rest1",
        ]));

        setup();
        replace_program(ROOM);
}

