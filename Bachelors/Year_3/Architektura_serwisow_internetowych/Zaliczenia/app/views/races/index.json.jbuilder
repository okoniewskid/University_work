json.array!(@races) do |race|
  json.extract! race, :id, :name, :description
  json.url race_url(race, format: :json)
end
