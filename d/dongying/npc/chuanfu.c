// chuanfu.c �ϴ���

#include <ansi.h>
inherit NPC;
int  chu_hai();
void goto_dao(object ob);
void create()
{
        set_name("�ϴ���", ({ "lao chuanzhang","chuanzhang","lao" }));
        set("gender", "����");
        set("age", 56);
        set("long",
        "����һ���ϴ�����������˪������͸��һ˿�ƻ�����������������ǰ����\n"
        "�Ǹ�������孵������ˡ�������ӵ��һ�Ҵ󴬿��Գ�����\n",
            );
        set("combat_exp", 500000);
        set("daoxing", 100000);
        set("attitude", "peaceful");
	set("max_kee", 1000);
	set("max_sen", 1000);
	set("max_gin", 2500);
	set("force", 2000);
	set("max_force", 2000);
 	set("force_factor", 100);
 	set("max_mana", 2000);
 	set("mana", 2000);
 	set("mana_factor", 100);
        set_skill("force", 100);
        set_skill("unarmed", 200);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set("inquiry", ([
                
                "��孵�" : "��孵���������ٵ�һ���󵺣���˵���ϵ����书����������\n",
                "����" :   (: chu_hai :),
        ]) );
        setup();
        carry_object("/d/dongying/obj/cloth")->wear();
 }
int chu_hai()
{
  object ob ;
  ob = this_player ( ) ;
  message_vision("�ϴ����������´�����$Nһ�£���Ҫ��������Ҫ���������ҿ���ѽ����\n"
                 "�ϴ���������һ�£��������һ�����ӣ�������Կ��ǡ�\n"
                 ,ob);
  ob->set_temp ("����" , 1 );
  return 1;
}
int accept_object(object who, object ob)
{
	object myenv;
    if (!(int)who->query_temp("����"))
    {
    message_vision("�ϴ���Ц�Ŷ�$N˵�������Ǯ��ʲô���������Լ����Űɣ�\n", who);
    return 0 ;
    }
    if (ob->query("money_id") && ob->value() >= 10000) {
        message_vision("�ϴ�����$N˵���ã���Ȼ��λ" + RANK_D->query_respect(who) +
        "������Ǯ��\n���Ҿʹ���ȥһ�ɰɣ�\n" , who);
        this_player()->delete_temp("����" );
        message_vision("�ϴ���һ���֣������������ᴬ��\n", who);
        message_vision("һ������ê��֮�󣬴��Ϳ�����.....\n", who);
        myenv = environment (who) ;
        who->move ("/d/dongying/dahai");
        tell_object(who, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
    call_out("goto_shenlong",20,who) ;
        return 1;
    }
    else  
    message_vision("�ϴ�����ü��$N˵��������Ҳ̫���˰ɣ�\n", who);
    return 0;
}
void goto_shenlong (object ob)
{
        if( !ob || ob->is_ghost()) return;
   tell_object(ob , "������ͣ����һ��С���ĺ��۱ߡ������´�����\n" ) ;
   ob->move ("/d/dongying/haigang2") ;
}

