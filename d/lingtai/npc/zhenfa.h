
#include <ansi.h>

string* names = ({
        "guang jingzi",
        "guang guanzi",
        "guang mingzi",
        "guang zhizi",
        "guang hezi",
        "guang jizi",
        "guang wenzi",
        "guang xinzi",
});

string* saywords=({
        "һס���Ѽ�ʮ�꣬",
        "��ͷ��������ߡ�",
        "����ͤ�������ӣ�",
        "��Ҷ����̫���ɡ�",
        "�����������⣬",
        "��������δ��ǰ��",
        "����һЦ�޾а���",
        "�������������죡",
        });
        
mapping oldexits;

string ask_sixiang()
{
        mapping skl; 
        object fighter, me ;
        string *sname;
        int i,j;

        fighter = this_player();
        me = this_object();

        skl = fighter->query_skills();
        if (sizeof(skl) <= 1)
                return RANK_D->query_respect(fighter) + 
                "���������������ʸ�������";
        sname  = keys(skl);
        for(i=0; i<sizeof(skl); i++) {
                if ((skl[sname[i]] < 100) || (sizeof(skl) == 0))
                return RANK_D->query_respect(fighter) + 
                "���������������ʸ�������";
        }
        if( fighter->query("sixiang_winner") )
                return RANK_D->query_respect(fighter) + 
                "��Ȼ���������󣬿ɲ�Ҫ�������Ц��";

        if( fighter->query("family/family_name")!="����ɽ���Ƕ�")
                return RANK_D->query_respect(fighter) + "���Ǳ������ˣ���ʲô������";

        if ( me->query("assigned_sixiang")||me->query("assigned_bagua") )
                return RANK_D->query_respect(fighter) + 
                "�����������˴������һ��ʱ�������ɡ�";

        command("say �ðɣ������ҵ�����յ��ϴ���ɣ�");

        me->set("assigned_sixiang", fighter->query("id"));              
        message_vision("\n��������ƮȻ�����뿪��\n", fighter);
        me->move("/d/lingtai/wuchang");
        tell_room(environment(me),"��������˵�������׼�����ˣ����˴���\n");

        call_out("waiting", 1, me);

        return "�ã���Ҷ������ˡ�\n";
}

string ask_bagua()
{
        mapping skl; 
        object fighter, me ;
        string *sname;
        int i,j;

        fighter = this_player();
        me = this_object();

        skl = fighter->query_skills();
        if (sizeof(skl) <= 1)
                return RANK_D->query_respect(fighter) + 
                "���������������ʸ񴳰�����";
        sname  = keys(skl);
        for(i=0; i<sizeof(skl); i++) {
                if ((skl[sname[i]] < 100) || (sizeof(skl) == 0))
                return RANK_D->query_respect(fighter) + 
                "���������������ʸ񴳰�����";
        }
        if( fighter->query("bagua_winner") )
                return RANK_D->query_respect(fighter) + 
                "��Ȼ���������󣬿ɲ�Ҫ�������Ц��";

        if( fighter->query("family/family_name")!="����ɽ���Ƕ�")
                return RANK_D->query_respect(fighter) + "���Ǳ������ˣ���ʲô������";

        if ( me->query("assigned_sixiang")||me->query("assigned_bagua") )
                return RANK_D->query_respect(fighter) + 
                "�����������˴������һ��ʱ�������ɡ�";

        command("say �ðɣ������ҵ�����յ��ϴ���ɣ�");

        me->set("assigned_bagua", fighter->query("id"));                
        message_vision("\n��������ƮȻ�����뿪��\n", fighter);
        me->move("/d/lingtai/wuchang");
        tell_room(environment(me),"��������˵�������׼�����ˣ����˴���\n");

        call_out("waiting", 1, me);

        return "�ã���Ҷ������ˡ�\n";
}

int waiting(object me)
{
        object fighter;
        int wait_time;

        if( wait_time == 300 )
        {
                say( "��������˵�����������������ˣ�����û�õĶ�����\n\n");
                call_out("do_back", 0, me);             
        }

        if((me->query("assigned_sixiang")&&!objectp(fighter=present( me->query("assigned_sixiang"), environment(me))))||
            (me->query("assigned_bagua")&&!objectp(fighter=present( me->query("assigned_bagua"), environment(me)))))
        {
                wait_time++;
                call_out("waiting", 1, me);
        }
        else    call_out("preparing", 1, me, fighter);

        return 1;
}

int preparing(object me, object fighter)
{
        object room;
        string zhname;

        if(!( room = find_object("/d/lingtai/wuchang")) )
        room = load_object("/d/lingtai/wuchang");
        
        if(me->query("assigned_sixiang")){
            zhname="������";
            message("vision", HIY "\n�������˴����������������Χ��\n" NOR, room);
            message("vision", "\nֻ����������ɳɳ�ĽŲ�������λ����������ɱ��\n"
                "�ֳ�ľ�ȣ��ֳ��ķ�������Χ����������ס��ͨ·��\n\n", room);
        }else{
            zhname="������";    
            message("vision", HIY "\n�������˴����������������Χ��\n" NOR, room);
            message("vision", "\nֻ����������ɳɳ�ĽŲ�������λ����������ɱ��\n"
                "�ֳ�ľ�ȣ�վס�˸���λ����ס��ͨ·��\n\n", room);
        }
        oldexits=room->query("exits");
        room->delete("exits");

        say( HIY"���������ֵ���׼����"+zhname+"���̷�����\n\n"NOR);

        fighter->delete_temp("beat_count");
        fighter->set_temp("fighting", 1);

        if(me->query("assigned_sixiang"))call_out("fighting",  5, me, fighter, 0);
        else call_out("bfighting",  5, me, fighter, 0);

        return 1;
}

int fighting(object me, object fighter, int count)
{
        object daoshi1, daoshi2, room1, room2;

        if(!( room1 = find_object("/d/lingtai/xiuwu")) )
        room1 = load_object("/d/lingtai/xiuwu");

        if(!( room2 = find_object("/d/lingtai/wuchang")) )
        room2 = load_object("/d/lingtai/wuchang");

        if( count <4 ) {
                message("vision", HIW"\n����Ѹ�����ߣ�ֻ������˫˫������\n" NOR, room2);

                daoshi1 = present(names[count*2%4], room1);
                daoshi1->move(room2);
                daoshi2 = present(names[count*2%4+1], room1);
                daoshi2->move(room2);

                message("vision", HIW+daoshi1->query("name")+"��"
                   +daoshi2->query("name")+"���˸���һ�к�Ѹ���˻�ԭλ��\n" NOR, room2);
                daoshi1->move(room1);
                daoshi2->move(room1);
        }

        if( !find_player(me->query("assigned_sixiang")) ||
        !living(fighter) || fighter->query("kee") <= 1 )
        {
                if( objectp(present(me->query("assigned_sixiang"), environment(me)) )) {
                        fighter->delete_temp("fighting");
                        fighter->delete_temp("beat_count");
                }

                say( "��������ҡ��ҡͷ��˵�����벻�� ... ����\n\n");
                command("sigh");
                call_out("do_back", 5, me );
        }
        else if( count >= 3 )
        {
                if( (int)fighter->query_temp("beat_count") >= 8 )       
                        call_out("do_recruit", 5, me, fighter);
                else
                        call_out("do_back", 5, me );
        }
        else
        {
                count++;
                call_out("fighting", 2, me, fighter, count);
        }
 
        return 1;
}

int bfighting(object me, object fighter, int count)
{
        object daoshi1, room1, room2, room3;

        if(!( room1 = find_object("/d/lingtai/xiuwu")) )
              room1 = load_object("/d/lingtai/xiuwu");

        if(!( room2 = find_object("/d/lingtai/wuchang")) )
              room2 = load_object("/d/lingtai/wuchang");

        if(!( room3 = find_object("/d/lingtai/yangxin")) )
              room3 = load_object("/d/lingtai/yangxin");

        if(count==0)
            message("vision", HIW"\n������Ѹ����ת��£��\n" NOR, room2);
        if( count <4 ) {
                daoshi1 = present(names[count], room1);
                message("vision", HIW"ֻ��"+daoshi1->query("name")+"������"+saywords[count]+"\n"NOR, room2);
                daoshi1->move(room2);

                daoshi1->move(room1);
        }else if( count <8 ) {
                daoshi1 = present(names[count], room3);
                message("vision", HIW"ֻ��"+daoshi1->query("name")+"������"+saywords[count]+"\n"NOR, room2);
                daoshi1->move(room2);
                daoshi1->move(room3);
        }
        message("vision", HIW+daoshi1->query("name")+"Ѹ���˻�ԭλ��\n" NOR, room2);

        if( !find_player(me->query("assigned_bagua")) ||
        !living(fighter) || fighter->query("kee") <= 1 )
        {
                if( objectp(present(me->query("assigned_bagua"), environment(me)) )) {
                        fighter->delete_temp("fighting");
                        fighter->delete_temp("beat_count");
                }

                say( "��������ҡ��ҡͷ��˵�����벻�� ... ����\n\n");
                command("sigh");
                call_out("do_back", 5, me );
        }
        else if( count >= 7 )
        {
                if( (int)fighter->query_temp("beat_count") >= 8 )       
                        call_out("do_recruit", 5, me, fighter);
                else
                        call_out("do_back", 5, me );
        }
        else
        {
                count++;
                call_out("bfighting", 2, me, fighter, count);
        }
 
        return 1;
}


int do_recruit(object me, object fighter)
{
        fighter->delete_temp("beat_count");
        fighter->delete_temp("fighting");
        fighter->add("combat_exp", 5000);
        if(me->query("assigned_sixiang"))fighter->set("sixiang_winner", 1);
        else if(me->query("assigned_bagua"))fighter->set("bagua_winner", 1);

        command("bow");
        say("��������˵����" + RANK_D->query_respect(fighter) + "�˷����󣬵��Ա������д������棬�ٳ߸�ͷ������һ�����ϵ��ʹ˱����\n");
        
        call_out("do_back", 2, me );
        return 1;
}

int do_back(object me)
{
        object room;
        
        if(!(room=find_object("/d/lingtai/wuchang")))
            room=load_object("/d/lingtai/wuchang");
        room->set("exits",oldexits);    
        me->delete("assigned_sixiang");
        me->delete("assigned_bagua");
        
        me->move("/d/lingtai/jingtang");

        return 1;
}

