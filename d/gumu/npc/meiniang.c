//��ԯ��Ĺ����ʦ��
inherit NPC;
inherit F_SAVE; 
#include <ansi.h>
inherit F_MASTER;
int rank_me();
#include <ansi.h>

void create()
{
       set_name("������", ({"hu meiniang", "hu", "meiniang","master"}));
       set("long",
"ԭ����һֻС���꣬������������ڻ�������\n");
       set("title", "С���꾫");
       set("gender", "Ů��");
       set("age", 18);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("rank_info/respect", "���");
       set("per", 40);
        set("int", 30);
       set("max_kee", 500);
       set("max_gin", 500);
       set("force", 500);
       set("max_force", 500); 
       set("force_factor", 20);
       set("max_mana", 300);
       set("mana", 300);
       set("mana_factor", 20);
       set("combat_exp", 200000);
  set("daoxing", 100000);


        set("eff_dx", 70000);
        set("nkgain", 260);

       set_skill("literate", 20);
       set_skill("unarmed", 50);
       set_skill("dodge", 80);
       set_skill("force", 50);
       set_skill("parry", 50);
       set_skill("sword", 50);
       set_skill("spells", 50);
        set_skill("youming-spells", 60);
        set_skill("jiuyin-zhua", 60);
        set_skill("qinghu-jian", 60);
        set_skill("jiuyin-force", 60);
        set_skill("kongming-steps", 60);
        map_skill("spells", "youming-spells");
        map_skill("unarmed", "jiuyin-zhua");
        map_skill("force", "jiuyin-force");
        map_skill("sword", "qinghu-jian");
        map_skill("parry", "snowsword");
        map_skill("dodge", "kongming-steps");
        set("inquiry", ([

         "ְλ": (: rank_me :),
                ]) );
create_family("��ԯ��Ĺ", 3, "����");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
      //  carry_object("/d/moon/obj/guihuajian")->wield();
}

int rank_me() 
{
             object me=this_player(); 
             object ob=this_object(); 
             int ep; 
        ep=(int)me->query("combat_exp");
        if( me->query("title") == "��ԯ��Ĺ����")
                return notify_fail("���Ѿ����������ˣ�����Ҫʲôְλ��\n");
        if( me->query("gender") == "����")
                return notify_fail("������԰���\n");
        if( (string)me->query("family/family_name") == "��ԯ��Ĺ"){
                if( ep <= 100000 ){
                        me->set("title", HIW"��ԯ��Ĺ"HIG"���꾫"NOR);
                  } else if(ep <= 3000000 ){
                        me->set("title", HIW"��ԯ��Ĺ"HIM"�Ļ�����"NOR);
                  } else if(ep <= 5000000 ){
                        me->set("title", HIW"��ԯ��Ĺ"HIM"��������"NOR);
                  } else if(ep <= 15000000 ){
                        me->set("title", HIW"��ԯ��Ĺ"HIR"����ʥŮ"NOR);
                } else {
                        me->set("title", HIW"��ԯ��Ĺ"HIB"����ʥĸ"NOR);
                }

                tell_object(me, "�������˵���������"+me->query("title")+"��\n");
//              command("say �������"+me->query("title")+"��\n");
                tell_room(environment(me),
"�������"+me->query("name")+"˵���������"+me->query("title")+"��\n", ({me, me}));
     me->save();  
        }
return 1; 
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="Ů��")){
           command("shake");
           command("say ��ֻ��Ůͽ����λ" +
RANK_D->query_respect(ob) + "����ȥ������������԰ɡ�\n");
           return;
        }

        command("wink "+ob->query("id"));
        command("kiss "+ob->query("id"));
        command("say ������" + RANK_D->query_respect(ob) +
"Ҫ���Ŭ��Ŷ��\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yaomo");

}

