// ������ by Calvin
#include <ansi.h>
inherit NPC;
void create()
{
    set_name("������", ({ "xiang shijie", "xiang", "shijie","boss" }));
    set("title", HIG "��Ե����" NOR);
    set("nickname", HIW "��ʥ" NOR );
    set("shen_type", 1);
    set("str", 40);
    set("per", 40);
    set("gender", "����");
    set("age", 20);
    set("long",
        "�����������ר�Ÿ��˸����ֵġ�\n");
    set("combat_exp", 150000);
    set("attitude", "friendly");
    set("inquiry", ([
        "����" : "����˵�ҷǷ������������ҵ�ִ������ȥ�ұ��˰ɣ�",
    ]));
    
    setup();
    carry_object("/d/obj/cloth/linen")->wear();
}
void init()
{
    object ob;
    
    ::init();
    if (interactive(ob = this_player()) && !is_fighting()) {
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
    }
/*
    add_action("do_name","��");
    add_action("do_name","change");
*/
}
void greeting(object ob)
{
    if (!ob || environment(ob) != environment())
        return;
    switch(random(2)) {
    case 0 :
        say("������Ц���е�˵������λ" + RANK_D->query_respect(ob) +
            "���������Ъ�����ɡ�\n");
        break;
    case 1 :
        say("������˵����Ӵ����λ" + RANK_D->query_respect(ob) + 
            "�����˰���������˼������ִ����ʱ���������޷�Ϊ���������գ�\n");
        break;
    }
}
/*
int accept_object(object who, object ob)
{
    
    if (ob->query("money_id") && ob->value() >= 1000000)
    {
        tell_object(who, "������Ц���е�˵�����ðɣ�����������ȡ��ʲô���������֡�\n");
        tell_object(who, "����룺�� �µ���������\n");
        who->set_temp("fee_paid",1);
        return 1;
    }
    else if (ob->query("money_id") && ob->value() < 1000000) 
    {
        tell_object(who, "�����ܺٺ�һЦ��˵�������������Ǯ�� �����ҿ�û�����㰡��\n");
        return 1;
    }
    return 0;
}
int do_name(string target)
{
    object me;
    string old_name;
    me = this_player();
    old_name = me->query("name");
    if( !me->query_temp("fee_paid") ) 
        return notify_fail("�����������˵�������ܽ�����ʲ�ᣬ���ɵ��ȸ�Ǯ�ģ�\n");
    if( !target) 
        return notify_fail("�������Ի󲻽��˵��������������µ�����ѽ��\n");
    if( old_name == target )
        return notify_fail("��������ֵض���˵��������Ǯ�ǲ�������̫�����ˣ�\n");
    if (!LOGIN_D->check_legal_name(target))
        return notify_fail("������ֲ��Ϸ���������һ�����ְɣ�\n");
    me->delete_temp("fee_paid");
    me->set("name", target);
    command("chat " + old_name + "(" + me->query("id") +")�����ڿ�ʼ����Ϊ��" + me->query("name") + "������Ժ���ϴ����ˣ�\n");
    return 1;
}


*/
