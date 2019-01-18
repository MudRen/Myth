// ���й��� yhguanshi.c
// 99.12.14 lizuole

#include <ansi.h>
#include <login.h> 
inherit NPC;
//inherit F_VENDOR_SALE;

void create()
{
     //  reload("guanshi");
       set_name("��ʦ��", ({"guanshi","guan shi"}));
       set("gender", "����");
       set("title", HIC"���й���"NOR);
       set("combat_exp", 100000);
       set("age", 26);
       set("per", 24);
       set("attitude", "friendly");
       set("long","��ʦ��ԭ������˫ȫ���������ֺʹ��ƹ���̫�ڵ�����г����\n���Եò�����͢�����á�����������������ʶ����Ϊ���й��¡�\n");
       set("shen_type", 1);
      
       set("max_kee", 1100);
       set("max_gin", 1100);
       set("max_sen", 1100);
       set("force", 2300);
       set("max_force", 1200);
       set("force_factor", 80);
       set("max_mana", 1200);
       set("mana", 2300);
       set("mana_factor", 60);
       set("combat_exp", 800000);

       set("eff_dx", 250000);
       set("nkgain", 400);

       set_skill("literate", 90);
       set_skill("unarmed", 120);
       set_skill("dodge", 120);
       set_skill("parry", 120);
       set_skill("stick", 120);
       set_skill("spells", 120);
       set_skill("dao", 120);
       set_skill("puti-zhi", 120);
       set_skill("wuxiangforce", 120);
       set_skill("force", 120);
       set_skill("qianjun-bang", 120);
       set_skill("jindouyun", 120);
       map_skill("spells", "dao");
       map_skill("unarmed", "puti-zhi");
       map_skill("force", "wuxiangforce");
       map_skill("stick", "qianjun-bang");
       map_skill("parry", "qianjun-bang");
       map_skill("dodge", "jindouyun");
       
       setup();

       carry_object("/d/lizuole/obj/choupao")->wear();
       add_money("gold", 1);
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 3);
        set("inquiry", ([
                "name" : "���²��ţ�������ʦ����",
                "here" : "���������������������Ǳ�����С�\n",
                "lizuole" : "���ǹ����书��Ȼ���Ǻܺã������������ѱ����£�������֪���ֵ��ĸ�������ȥ�����ˡ����������������ڼҡ�\n",
                "lzl" : "���ǹ����书��Ȼ���Ǻܺã������������ѱ����£�������֪���ֵ��ĸ�������ȥ�����ˡ����������������ڼҡ�\n",
                "����" : "���ǹ����书��Ȼ���Ǻܺã������������ѱ����£�������֪���ֵ��ĸ�������ȥ�����ˡ����������������ڼҡ�\n",
                "xueer" : "�����������ں���Ъ���أ�",
                "ѩ��" : "�����������ں���Ъ���أ�",
                "������" : "�����������ں���Ъ���أ�",
   ]) );

        set("chat_msg", ({
                "��ʦ������˵��������ү��ύ�����ˡ�\n",   
                "��ʦ���������´������㼸�ۡ�\n",
                "��ʦ������˵�������ܵ����������ܶ඼�����ǹ��ӵ����ѡ�\n",
                "��ʦ������˵�������ϵ����Ѷ����������үһЩ���档���Ժ������������ҡ�\n",
                "��ʦ��������˵����������������ӣ�����˵�����˲�������������϶��������졣\n"
                
       }) );
}

/*void greeting(object ob)
{
  if( !ob || !visible(ob) || environment(ob) != environment() ) return;
  command("say ��λ" + RANK_D->query_respect(ob) +"��������");
}*/

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) {  // 1/3 chance to greet.
                case 0:
                        say( name()+"Ц�����˵������λ" +
RANK_D->query_respect(ob)
                                + "����������\n");
                        break;
        }
}

void accept_kill(object me)
{       object ob;
        if(is_fighting()) return;
        if( query("called") ) return;

        command("help!");

        ob=present("xunluo guanbing");
        if( !ob) {
                seteuid(getuid());
                ob=new("/d/lizuole/npc/lizuole");
                ob->move(environment());
        }
        message_vision("\n��Ȼ�����ִ�������������$N��һ������ʲô����ɱ��ı��ô��\n\n",me);        

        ob->kill_ob(me);
        ob->set_leader(me);
        me->fight_ob(ob);
        set("called", 1);
        call_out("regenerate", 300);
        
        me->add("daoluan",1);
        me->save();

}
int regenerate()
{
        set("called", 0);
        return 1;
}
