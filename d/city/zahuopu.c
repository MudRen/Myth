//Cracked by Roath
//changan city

inherit ROOM;

void create ()
{
        set ("short", "�����ӻ���");
        set ("long", @LONG

��֪Ϊʲô�������ȴֻ����һ���ӻ��̡�����ÿ������������Ҳ
ͦ���֡��������������ν��ף����Ǵ��װ��棬������ȫ�������ɨ
��Ҳʮ�ָɾ���κ�ϰ��ںͼ�λ����˵˵ЦЦ��
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"east" : __DIR__"beiyin5",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/laotou" : 1,
		"/d/xueshan/npc/xunshi-out": 1,
"/obj/boss/city_laowei": 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


