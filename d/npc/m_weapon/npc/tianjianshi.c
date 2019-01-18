// npc: /d/xingxiu/npc/afanti.c
// Jay 3/26/96
// modify by five
#include <ansi.h>
inherit NPC;

int do_weapon();
object creat_weapon();

void create()
{
        set_name("ŷұ��", ({ "ouye zi", "zi" }) );
        set("nickname", RED "���Ľ���" NOR );
          set("title", "������ʦ" );
        set("gender", "����" );
        set("age", 60);
        set("long",     
            "��ͷ�ϰ���ͷ�����Ƴ���Ʈ����ǰ����Ŀ���ݵ������й⣬\n"
            "��Ŀ��������˸˸���ž��������ݵĽ��⣬�����ƺ�����Χ\n"
            "��һ�ɽ���֮�С�\n");
        set("str", 25);
        set("kar", 17);
        set("int", 30);
        set("daoxing", 3000000);
        set("combat_exp", 5000000);

        set_skill("unarmed", 340);
        set_skill("dodge", 340);
        set_skill("parry", 340);
        set_skill("spells", 340);  
        set_skill("dao", 340);
        set_skill("literate", 340);
        set_skill("stick", 340);  
        set_skill("qianjun-bang", 340);
        set_skill("puti-zhi", 340);  
        set_skill("jindouyun", 340);
        set_skill("dodge", 340);  
        set_skill("force", 340);   
        set_skill("wuxiangforce", 340);

        map_skill("spells", "dao");
        map_skill("unarmed", "puti-zhi");
        map_skill("force", "wuxiangforce");
        map_skill("stick", "qianjun-bang");
        map_skill("parry", "qianjun-bang");
        map_skill("dodge", "jindouyun");


        set("per", 30);
        set("max_kee", 2000);
        set("max_gin", 2000);
        set("max_sen", 2000);
        set("force", 4500);
        set("max_force", 4500);
        set("force_factor", 100);
        set("mana", 4500);
        set("max_mana", 4500);
        set("mana_factor", 100);
        
        set("inquiry", ([
            "����"  : "�������Ǽ�ʮ�ּ����£�Ҫ�����˵ľ��������������о��ĺ�������\n",
            "ԭ��"  : "��������ǧ���������������ҵ����Ҳ��ܰ���������\n",
       ]) );
            set("no_get",1);
        setup();
        set("chat_chance", 3);
        set("chat_msg", ({
             "ŷұ�Ӹ������裺��������⣬�����͡����������⣬��Ӣ�ۣ�\n",
             "ŷұ�ӵ�ͷ�������ƺ���˼��ʲô��\n"
             "ŷұ��̾��һ�����������Ӣ�ۣ���Ӣ�ۡ�����������\n"
       }) );
        carry_object("/d/obj/cloth/choupao")->wear();
        carry_object("/d/obj/weapon/stick/bintiegun")->wield();
}

void init()
{
        ::init();
        add_action("do_answer","answer");
}


int accept_object(object who, object ob)
{       
        if(!who->query("bld/done") ){
                say("ŷұ��һ��̾�����������С������������ܰ������\n");
                return 2;
        }
        if((who->query("weapon/make")) ){
                say("ŷұ��һ��ãȻ�����Ѿ���һ������������ˣ�������ʲô���ѵ�������ô��\n");
       call_out("destrory",0,ob);
                return 2;
        }
        switch ((string)ob->query("name") ) 
        {
                case "ǧ����ľ": 
                        who->set_temp("or",1);
                        who->set_temp("get_orc",1);
                        break;
                case "���׽�ĸ":
                        who->set_temp("or",2);
                        who->set_temp("get_orc",1);
                        break;
                case "��˿����": 
                        who->set_temp("or",3);
                        who->set_temp("get_orc",1);
                        break;
                default :
                        message("vision","����ʲô���ⲻ���������������",who);
                        return 2;
        }
        message("vision","ŷұ�ӵ�ͷ������һ�����е�"+(string)ob->query("name")+
                        "���˵�ͷ˵��\n",who);

        write("��������Դ������±�����\n"+
              "     ��(sword)\n"+
              "     ��(blade)\n"+
              "     ��(stick)\n"+
              "     ��(staff)\n"+
              "     �(hammer)\n"+
              "     ǹ(spear)\n"+
              "     �(mace)\n"+
              "     ��(axe)\n"+
              "     ��(fork)\n"+
              "     ��(whip)\n");               
        say("��λ"+RANK_D->query_respect(who)+"Ҫ��ʲô�����������˸�����(answer)��\n");
       call_out("destrory",0,ob);
        return 2;

}

int do_answer(string arg)
{
        object me,w_or;
        me = this_player();
        if(!(me->query_temp("get_orc") ) ){
                write("���ҵ�ԭ������\n");
                return 0;
        }
        
        if(!arg){
           write("��Ҫ��ʲô������\n");
          return 0;
        }
        message("vision",me->name()+"��ŷұ������˵�˼��䡣\n",environment(me), ({me}) );
        switch (arg) {
          case "sword" :
                me->add_temp("sword",1);
                write("����ԭ��ȥ���̽���!\n");
                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);
                break;
          case "blade" :
                me->add_temp("blade",1);
                write("����ԭ��ȥ���̵���!\n");
                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);
                break;
          case "stick" :
                me->add_temp("stick",1);
                write("����ԭ��ȥ���̹���!\n");
                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);
                break;
          case "staff" :
                me->add_temp("staff",1);
                write("����ԭ��ȥ�����Ȱ�!\n");
                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);
                break;
          case "whip" :
                me->add_temp("whip",1);
                write("����ԭ��ȥ���̱ް�!\n");
                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);
                break;
          case "spear" :
                me->add_temp("spear",1);
                write("����ԭ��ȥ����ǹ��!\n");
                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);
                break;
          case "mace" :
                me->add_temp("mace",1);
                write("����ԭ��ȥ����ﵰ�!\n");
                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);
                break;
          case "axe" :
                me->add_temp("axe",1);
                write("����ԭ��ȥ���̸���!\n");
                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);
                break;
          case "fork" :
                me->add_temp("fork",1);
                write("����ԭ��ȥ���̲��!\n");
                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);
                break;
          case "hammer" :
                me->add_temp("hammer",1);
                write("����ԭ��ȥ���̴���!\n");
                message("vision","ȥ�ɣ�"+me->name()+"!\n",me);
                break;

          default :
                message_vision(HIC "ŷұ��һ�����ɣ�ʲô������\n" NOR,me);
                return notify_fail("ŷұ����ϸ��˵�����²��ɶ�Ϸ��������!!\n");
        }
        switch ( me->query_temp("or") ) {
          case 1:
                w_or = new("/m_weapon/tan/item/shenmu",1);
                w_or->move(me);
                message_vision(HIC "ŷұ�Ӹ���$Nһ��ǧ����ľ\n" NOR, me);
                break;
          case 2:
                w_or = new("/m_weapon/tan/item/jinmu",1);
                w_or->move(me);
                message_vision(HIC "ŷұ�Ӹ���$Nһ�麣�׽�ĸ\n" NOR, me);
                break;
          case 3:
                w_or = new("/m_weapon/tan/item/hanzhu",1);
                w_or->move(me);
                message_vision(HIC "ŷұ�Ӹ���$Nһ�麮˿����\n" NOR, me);
                break;
        }
        me->delete_temp("or");
        return 1;
}
void destrory(object ob)
{
      destruct(ob);
     return;
}
