inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
    set_name(HIC "�����" NOR, ({"hua", "feicui"}));
        set("unit", "��");
    set("long", "����һ��ǧ���ѵ�һ���������,��˵�ܽ�ٶ���\n");
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))  return notify_fail("��Ҫ��ʲô��\n");
    this_player()->set_temp("nopoison", 1);
    this_player()->set("eff_sen",this_player()->query("max_sen"));
    this_player()->set("sen",this_player()->query("max_sen"));
    this_player()->set("eff_kee",this_player()->query("max_kee"));
    this_player()->set("kee",this_player()->query("max_kee"));
    message_vision(HIG "$Nֻ��һ�����������ķ�,��ʱ��̨һƬ����,������ˬ��\n" NOR,this_player() );
       this_object()->move(VOID_OB);
    destruct(this_object());
    return 1;
}

