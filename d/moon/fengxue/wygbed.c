// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG

һ����ɫ����齣�����ܵ�����Ҷ�񣬿���ȥ��Ϊ���¡�����
����һ��ɴᣣ����治֪��ʲô˿������һ����������¡�ɴ
��ԧ��֮��ɢ����һ˿˿���������㡣
LONG
        );
        
        set("exits", ([
                "out": __DIR__"woshi",
            ]));
        set("no_fight", 1);
        set("no_magic", 1);
        set("sleep_room",1);
        set("if_bed",1);
                                              
        setup();
}


