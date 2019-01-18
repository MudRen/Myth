//�����Ÿ�����֮��ġ��Ѻöȡ���
//Qyz
#include <ansi.h>

inherit F_SAVE;

#define FAMILY_ENEMY    2
#define FAMILY_FRIEND   1

mapping ALL_FAMILYS=(["����ɽ���Ƕ�":1,
                 "�Ϻ�����ɽ":1,
                 "������":1,
                 "��ׯ��":1,
                 "���޵ظ�":-1,
                 "�¹�":1,
                 "��������":1,
                 "��ѩɽ":-1,
                 "�ݿ�ɽ�޵׶�":-1,
                 "��ɽ����":1,
                 "��ԯ��Ĺ":-1,
                 "����ɽ":-1,
                 "��˿��":1,
                 "���ƶ�":-1,
                 
                
]);

mapping MASTERS=(["����ɽ���Ƕ�":"��������",
                 "�Ϻ�����ɽ":"��������",
                 "������":"����",
                 "��ׯ��":"��Ԫ����",
                 "���޵ظ�":"������",
                 "�¹�":"�϶�",
                 "��������":"����",
                 "��ѩɽ":"��������",
                 "�ݿ�ɽ�޵׶�":"����",
                 "��ɽ����":"��ʥ",
                 "����ɽ":"������ʦ",
                 "���ƶ�":"ţħ��",
                 "��ԯ��Ĺ":"Ů�",
                 "��˿��":"��ϼ����",
                 
]);

mapping family;

void create()
{
    seteuid(getuid());
    if ( !restore() && !mapp(family) ){
        family = ([]);
    }
}

int remove()
{
    save();
    return 1;
}

int family_relation(string your_fam,string my_fam )
{
        return ALL_FAMILYS[your_fam]*ALL_FAMILYS[my_fam];
}

string query_save_file() { return DATA_DIR + "familyd"; }

int set_relation(string my_fam, mapping relation)
{
    family[my_fam] = relation;
    save();
    return 1;
}

int add_family_enemy( string my_fam, string name, int score )
{
    if( undefinedp( family[my_fam] ) )
        family[my_fam] = ([ name : score ]);
    if( !undefinedp(family[my_fam][name] ) )
        family[my_fam][name] += score;
    else family[my_fam] += ([ name : score ]);
    save();
    return 1;
}

int remove_family_enemy( string my_fam, string name )
{
    if( undefinedp( family[my_fam] ) ) return 0;
    else if( !undefinedp( family[my_fam][name] ) )
    {
        map_delete(family[my_fam] , name);
        save();
            return 1;
    }
    else return 0;
}

int is_family_enemy( string my_fam, string name )
{
    if( undefinedp( family[my_fam] )) return 0;
    else if( !undefinedp( family[my_fam][name])&&family[my_fam][name]>100)
        return 1;
    else return 0;
}

int query_enemy_quantity( string my_fam, string name )
{
    if( undefinedp( family[my_fam] )) return 0;
    else if( !undefinedp( family[my_fam][name] ) )
        return family[my_fam][name];
    else return 0;
}
        
mapping query_relation(string my_fam)
{
    if ( !undefinedp(family[my_fam]) )
        return family[my_fam];
    else
        return ([]);
}

int deal_family_relation( object victim, object killer )
{
    mapping my_family, your_family;
   
    int c_score, y_relation, m_relation; 
    string my_fam, your_fam, my_id, your_id, declare;

    string* sname;
    int i;

    your_id = killer->query("id");
    if( your_family = killer->query("family") )
    {
        your_fam = your_family["family_name"];
        my_id = victim->query("id");    
        if( !undefinedp(family[your_fam]) &&
        !undefinedp(family[your_fam][my_id]) )
        {
            killer->add("daoxing" , (victim->query("daoxing")/100) );
            {
                declare = sprintf("%sɱ�����ų��%s�����˴�����ġ�\n",
                                killer->name(1), victim->name(1) );
                message("channel:chat",GRN+MASTERS[your_fam]+declare+NOR,users());
            }
            map_delete(family[your_fam] , my_id );
            return 1;
        }

        if( my_family = victim->query("family") )
        {
            my_fam = my_family["family_name"];
            c_score = victim->query("faith");
            if( my_fam == your_fam )
            {
                killer->add("daoxing", -(victim->query("daoxing")/100));
                if(c_score > 30 )  
                {
                    declare = sprintf("%s��������¾����ʦ�ֵܣ��в������ﷴ����\n", killer->name(1) );
                    message("channel:chat",GRN+MASTERS[your_fam]+declare+NOR,users());                    
                }     
                return 1;                                             
            }
            else
            {    
                if( userp( killer ) )
                    add_family_enemy( my_fam, your_id, c_score );
                if( y_relation = family_relation( your_fam, my_fam ) )
                {                                           
                    if( y_relation == FAMILY_ENEMY )
                    {
                        killer->add("daoxing" , (victim->query("daoxing")/100) );
                        killer->add("relation/"+my_fam,c_score/100);
                        sname=keys(ALL_FAMILYS);
                        if(c_score > 30 )
                        {
                            declare = sprintf("%sɱ���˱��Ŷ�ͷ%s��%s����������Ҳ��\n",
                                    killer->name(1), my_fam, victim->name(1) );
                            message("channel:chat",GRN+MASTERS[your_fam]+declare+NOR,users());                            
                        }
                    }
                    else if( y_relation == FAMILY_FRIEND )
                    {
                        killer->add("daoxing" , (victim->query("daoxing")/100) );
                        killer->add("relation/"+my_fam,-c_score/100);       
                        if(c_score > 30 )
                        {
                            declare = sprintf("���ŵ���Ӧ����%s�ĵ��Ӻ����ദ����Ӧ����ɱ¾��\n",
                                        my_fam );
                            message("channel:chat",GRN+MASTERS[your_fam]+declare+NOR,users());
                        }
                    }
                }
                if( m_relation = family_relation( my_fam, your_fam ))
                {
                    if( m_relation == FAMILY_ENEMY )
                    declare = sprintf("������%s�Ʋ�������������Ҫ�мǳ�ް���\n",
                                        your_fam );
                    else
                    declare = sprintf("����%s��%s��%sɱ���ˣ�ͬ�ŵ��ӽ�Ӧ�Ա���Ϊ���Σ�\n",
                                    victim->name(1), your_fam, killer->name(1) );
           
                    message("channel:chat",GRN+MASTERS[my_fam]+declare+NOR,users());
                }
                return 1;                                              
            }             
        }
        else return 0;
    }
    else if( my_family = victim->query("family") )                   
    {
        my_fam = my_family["family_name"];
        c_score = victim->query("faith");
        if( userp(killer) )
            add_family_enemy( my_fam, your_id, c_score );
       killer->add("relation/"+my_fam,c_score/100);
        {
            declare = sprintf("���ŵ��ӱ�%sɱ���ˡ�\n", killer->name(1) );
            message("channel:chat",GRN+MASTERS[my_fam]+declare+NOR,users());
        }
        return 1;
    }
    else return 0;
}

void clear_all_family_relation( string id )
{
    int i;
    string *familys = keys(ALL_FAMILYS);
    for( i = 0; i<sizeof(familys); i++ )
    {
        if( undefinedp( family[familys[i]] ) ||
            undefinedp( family[familys[i]][id] ) )
        continue;
        map_delete( family[familys[i]], id );
    }
}
 
