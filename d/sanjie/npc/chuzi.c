// chuzi.c ����

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(WHT"СԲ��"NOR, ({"chu zi","chuzi"}));
        set("title", HIC"С����"NOR);
        set("gender", "����" );
        set("age", 16);
        set("long", "һ���Ե����ֵ�С��ʿ�������ջ�\n");
        set("combat_exp", 2000);
        set("attitude", "friendly");
        setup();

}
void init()
{
::init();
        add_action("do_yao", "yao");
}

int do_yao(string arg)
{
        object m,mm;
        message_vision("$N������ʵ����ֵܣ���������\n", this_player());

        if((int)this_player()->query("food") >=(int)this_player()->max_food_capacity()*90/100 )
        return notify_fail("����Ц����û�ǣ��ȿ���ʱ�����ɣ�\n");

        if((present("bao zi", this_player())))
        return notify_fail("����Ц������Ҫ��������ģ������Ź���ģ�����\n");
	
	if ( present("bao zi", environment()) )
                return notify_fail("����Ц�����ǲ�����һ�����������˵��\n");

        m=new("/d/sanjie/obj/gourou");
        mm=new("/d/sanjie/obj/gourou");


        m->move(this_player());
        mm->move(this_player());

        message_vision("���Ӷ�$NЦ�������˰ɣ�����ԡ�\n", this_player());
return 1;
}

