inherit ROOM;

void create()
{
        set("short", "��Ϣ��");
        set("long", @LONG
��������˼����������ӣ�û�а����κζ�������Ҳ���ṩ�κη���
�����ǲ�¥�ϰ��ص�Ϊ��Щ���������ڴ���ϵ��ο�׼���ģ���������Ϣ
֮�ã�����ȡ�κη��ã��ɼ��ϰ���ĵ�������
LONG);
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"chalou",
        ]));

        setup();
        replace_program(ROOM);
}

