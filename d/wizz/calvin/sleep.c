//���� kz_sleeproom

inherit ROOM;
void create()
{
        set("short", "��ջ˯��");
        set("long", @LONG

��ջ��һ��˯��������ɸɾ�����һ�Ŵ󴲣�����������Ϣ˯����

LONG);

        set("exits", ([
                "west" : "/d/calvin/kezhan",
            ]));

        set("sleep_room",1);
        set("if_bed",1);                             
        setup();
}
