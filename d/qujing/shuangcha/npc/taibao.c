//Cracked by Roath


inherit NPC;
#include <ansi.h>
int do_ok(string arg);

void create()
{
        set_name("������", ({"liu boqin","liu"}));
        set("gender","����");
        set("age",30);
        set("title",HIY"��ɽ̫��"NOR);
        set("long","ɽ�е�һ���Ի���ʮ�ֵĴ�׳��");
        set("per", 20);
        set("str", 50);
        set("attitude","friendly");
        set("combat_exp",100000);
        set("max_force",1000);
        set("force",1000);
        set("force_factor",40);
        set("max_kee",300);
        set("kee",300);
        set("sen",300);
        set("max_sen",300);
        set_skill("unarmed",80);
        set_skill("parry",80);
        set_skill("fork",100);

        set("inquiry",([
                "��ɽ̫��" : "��ɽ̫�������Ұ���",
                "here": "����ط�����˫����",
                ]));
        setup();

        carry_object("/d/obj/cloth/luoyi2")->wear();
        carry_object("/d/obj/weapon/fork/gangcha")->wield();
}

void init()
{
        object ob = this_player();
        remove_call_out("check");
        call_out("check",1,ob);
        add_action("do_ok","ok");
}
void check(object ob)
{
        if( this_object()->query("said") ) return ;
        if( environment()->query("short") == "ɽ��" && ob->query_temp("tiger_kill")=="yes")
        {
        command("say ��λ....����������������ɽ̫��Ҳ���簡��");
        command("say �粻���������Ҽ�һ�����(yes)�� ");
        this_object()->set("said",1);
        }
        return ;
}
int do_ok(string arg)
{
        object me = this_player();
        object ob = this_object();
        
   if(!me->query_temp("tiger_kill"))
	return 0;
   if( me->query("obstacle/sc") == "done"||me->query("obstacle/jz") != "done")
        {
        command("say �һ��е����顣\n");
        command("hehe");
        call_out("des",1,ob);
          return 0;
        }
         if( me->query("obstacle/jz") == "done")
        {
        command("say �ðɣ��������߰ɡ�");
        me->set_temp("sc/taibao_seen",1);
        
        me->move("/d/qujing/shuangcha/shanlu4");
        ob->move("/d/qujing/shuangcha/shanlu4");
        message_vision(HIR "$N����������ɽ�����˹�����"NOR,me);
        me->move("/d/qujing/shuangcha/shanlu5");
        ob->move("/d/qujing/shuangcha/shanlu5");
        message_vision(HIR "$N����������ɽ�����˹�����"NOR,me);
        me->move("/d/qujing/shuangcha/enter");
        ob->move("/d/qujing/shuangcha/enter");
        message_vision(HIR "$N�����������ǰ���˹�����"NOR,me);  
        me->move("/d/qujing/shuangcha/gate");
        ob->move("/d/qujing/shuangcha/gate");
        message_vision(HIR "$N����������������˹�����"NOR,me);  
        me->move("/d/qujing/shuangcha/yard");
        ob->move("/d/qujing/shuangcha/yard");
        message_vision(HIR "$N����������ͥԺ���˹�����"NOR,me);
        me->move("/d/qujing/shuangcha/yard");
        ob->move("/d/qujing/shuangcha/yard");
        message_vision(HIR "$N����������ͥԺ���˹�����"NOR,me);
        me->move("/d/qujing/shuangcha/zhengting");
        ob->move("/d/qujing/shuangcha/zhengting");
        message_vision(HIR "$N����������������˹�����\n"NOR,me);
        command("say �Եȣ����ҳ�ȥһ�ᡣ");
        destruct(ob);
        me->set_temp("home",1);        
	me->delete_temp("tiger_kill");
        return 1;
        }
}
void des()
{
        destruct(this_object());
}
